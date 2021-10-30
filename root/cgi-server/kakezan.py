import cgi
import sys
import io
import re

sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encodeing='utf-8')
print('Content-Type: text/html; charset=UTF-8\n')

html_body="""
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>Python CGI program</title>
</head>
<body>
    <p>aとbに数字を入れてください。</p>

    <form action="/cgi-bin/13_sum_001.py" method="post">
        <span>a: </span><input type="text" name="text1"><br>
        <span>b: </span><input type="text" name="text2"><br><br>
        <input type="submit" name="submit" value="計算">
    </form>

    <p>a x bは %s です。</p>
</body>
</html>"""

form=cgi.FieldStorage()
a=form.getvalue('text1','')
b=form.getvalue('text2','')

if re.compile("^\d+\.?\d*\Z").match(a) and re.compile("^\d+\.?\d*\Z").match(b):
    aa=float(a)
    bb=float(b)
    ss=round(aa * bb, 5)

else:
    ss="N/A"

print(html_body % (ss))