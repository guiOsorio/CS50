-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports
    WHERE street = "Chamberlin Street" AND month = 7 AND day = 28;
-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with
-- three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT name, transcript FROM interviews
    WHERE month = 7 AND day = 28;
-- Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
    -- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot
    -- in that time frame.
-- Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
    -- I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
-- Raymond | As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
    -- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    -- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Thief's car has one of these license plates
SELECT activity, license_plate, minute FROM courthouse_security_logs
    WHERE year = 2020 AND month = 7 AND day = 28 AND hour >= 10 AND hour < 11;
-- exit | 5P2BI95 | 16
-- exit | 94KL13X | 18
-- exit | 6P58WS2 | 18
-- exit | 4328GD8 | 19
-- exit | G412CB7 | 20
-- exit | L93JTIZ | 21
-- exit | 322W7JE | 23
-- exit | 0NTHK55 | 23

-- One of these is the thief's bank account number
SELECT account_number, transaction_type FROM atm_transactions
    WHERE atm_location = "Fifer Street" AND year = 2020 AND month = 7 AND day = 28
    AND transaction_type = "withdraw";
-- 28500762 | withdraw
-- 28296815 | withdraw
-- 76054385 | withdraw
-- 49610011 | withdraw
-- 16153065 | withdraw
-- 25506511 | withdraw
-- 81061156 | withdraw
-- 26013199 | withdraw

-- One of the numbers on the left column is the thief's phone number,
    -- while the corresponding number on the right is the thief's accomplice phone number
SELECT caller, receiver FROM phone_calls
    WHERE duration < 60 AND year = 2020 AND month = 7 AND day = 28;
-- (130) 555-0289 | (996) 555-8899
-- (499) 555-9472 | (892) 555-8872
-- (367) 555-5533 | (375) 555-8161
-- (499) 555-9472 | (717) 555-1342
-- (286) 555-6063 | (676) 555-6554
-- (770) 555-1861 | (725) 555-3243
-- (031) 555-6622 | (910) 555-3251
-- (826) 555-1652 | (066) 555-9701
-- (338) 555-6650 | (704) 555-2131

-- Thief has one of these passport numbers and sat on one of these seats on flight 36
SELECT passport_number, seat FROM passengers
    WHERE flight_id IN(
                        SELECT flights.id FROM flights
                            JOIN airports ON flights.origin_airport_id = airports.id
                        WHERE year = 2020 AND month = 7 AND day = 29
                        ORDER BY hour, minute
                        LIMIT 1
                      );
-- 7214083635 | 2A
-- 1695452385 | 3B
-- 5773159633 | 4A
-- 1540955065 | 5C
-- 8294398571 | 6C
-- 1988161715 | 6D
-- 9878712108 | 7A
-- 8496433585 | 7B

-- Thief's name
SELECT name FROM people
    WHERE passport_number IN(SELECT passport_number FROM passengers
                                WHERE flight_id IN(SELECT flights.id FROM flights
                                                        JOIN airports ON flights.origin_airport_id = airports.id
                                                    WHERE year = 2020 AND month = 7 AND day = 29
                                                    ORDER BY hour, minute
                                                    LIMIT 1)
                            )
    AND phone_number IN(SELECT caller FROM phone_calls
                        WHERE duration < 60 AND year = 2020 AND month = 7 AND day = 28)
    AND license_plate IN(SELECT license_plate FROM courthouse_security_logs
                        WHERE year = 2020 AND month = 7 AND day = 28 AND hour >= 10 AND hour < 11 AND minute >= 15 AND minute <= 25)
    AND id IN(SELECT person_id FROM bank_accounts
              WHERE account_number IN(SELECT account_number FROM atm_transactions
                                      WHERE atm_location = "Fifer Street" AND year = 2020 AND month = 7 AND day = 28
                                      AND transaction_type = "withdraw")
              );
-- Ernest

-- Accomplice name
SELECT name FROM people
WHERE phone_number IN(SELECT receiver FROM phone_calls
WHERE duration < 60 AND year = 2020 AND month = 7 AND day = 28 AND caller IN(SELECT phone_number FROM people
                        WHERE name = "Ernest")
                    );
-- Berthold

-- Thief's destination
SELECT city FROM airports
WHERE id IN(SELECT destination_airport_id FROM flights
            WHERE id IN(SELECT id FROM flights
                        WHERE id IN(SELECT flight_id FROM passengers
                                    WHERE passport_number IN(SELECT passport_number FROM people
                                                            WHERE name = "Ernest"
                                                            )
                                    )
                        )
            );

-- London

