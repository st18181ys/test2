from fastapi import FastAPI
from starlette.requests import Request

app=FastAPI(
    title='FastAPIでつくるtoDoアプリケーション',
    description='FastAPIチュートリアル：FastAPI(とstarlette)でシンプルなtoDOアプリを作りましょう.',
    version='0.9 beta'
)

def index(request:Request):
    return{'Hello':'World'}