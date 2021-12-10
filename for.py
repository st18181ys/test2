from fastapi import FastAPI

#from database import database

#インスタンス宣言
#db=database()
app=FastAPI()

@app.get("/")

async def main():

    #databaseから人数を抽出
    #dict_list=db.read()

    dict_list=[0,1,2,3,4]
    #json形式で返す"
    return {"people":dict_list[1]}