import os
from flask import Flask,request,redirect,url_for,flash
from werkzeug.utils import secure_filename
from flask import send_from_directory,render_template

UPLOAD_FOLDER='./uploads'
ALLOWED_EXTENSIONS=set(['png','jpg','gif'])
app=Flask(__name__)
app.config['UPLOAD_FOLDER']=UPLOAD_FOLDER

def allowed_file(filename):
    return '.' in filename and filename.rsplit('.',1)[1].lower() in ALLOWED_EXTENSIONS

@app.route('/',methods=['GET','POST'])
def uploads_file():
    if request.method=='POST':
        if 'file' not in request.files:
            flash('ファイルがありません')
            return redirect(request.url)
        file=request.files['file']
        if file.filename=='':
            flash('ファイルがありません')
            return redirect(request.url)
        if file and allowed_file(file.filename):
            filename=secure_filename(file.filename)
            file.save(os.path.join(app.config['UPLOAD_FOLDER'],filename))
            return redirect(url_for('uploaded_file',filename=filename))
    return render_template('index.html')

@app.route('/uploads/<filename>')
def uploaded_file(filename):
    return send_from_directory(app.config['UPLOAD_FOLDER'],filename)
