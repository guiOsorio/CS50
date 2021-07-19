import os
import qrcode

link = qrcode.make("https://secret-reaches-62371.herokuapp.com/campgrounds?fbclid=IwAR0Vx3wAHF8682EUyKfUlJCphpEnB8xdBfQVgy35tTpBc_DjZ8Lhx4IaIMQ")
link.save("qr.png", "PNG")
os.system("start qr.png")