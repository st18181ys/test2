from fastapi import FastAPI
from starlette.templating import Jinja2Templates
from starlette.requests import Request

app=FastAPI(
    title='FastAPIでつくるtoDoアプリケーション',
    description='FastAPIチュートリアル：FastAPI(とstarlette)でシンプルなtoDOアプリを作りましょう.',
    version='0.9 beta'
)

templates=Jinja2Templates(directory="templates")
jinja_env=templates.env

def index(request:Request):
    return templates.TemplateResponse('index.html',{'request':request})