from flask import Flask, request, json
from settings import token, confirmation_token
import messageHandler
import Db
#from array import array

app = Flask(__name__)
app.config['MYSQL_DATABASE_USER'] = 'phoudor11122'
app.config['MYSQL_DATABASE_PASSWORD'] = 'fe3rFGtg5'
app.config['MYSQL_DATABASE_DB'] = 'phoudor11122$default'
app.config['MYSQL_DATABASE_HOST'] = 'phoudor11122.mysql.pythonanywhere-services.com'


db = Db.DB()


@app.route('/')
def hello_world():
    return 'Hello nigga!'

@app.route('/', methods=['POST'])
def processing():
    data = json.loads(request.data)
    if 'type' not in data.keys():
        return 'format error'
    if data['type'] == 'confirmation':
        return confirmation_token
    elif data['type'] == 'message_new':
        messageHandler.create_answer(data['object'], token)
        return 'ok'
    elif data['type'] == 'send_data_smoke':
        command = 'INSERT INTO sensors_data (butan,metan,propan,vodorod,temperature) VALUES (%s,%s,%s,%s,%s)' % ( data['object']['butan'], data['object']['metan'], data['object']['propan'], data['object']['vodorod'], data['object']['temperature'])
        db.query(command)
        db.commit()
        return "ок"
    elif data['type'] == 'danger_data_smoke':
        command = 'select * from sensors_data'
        data = db.query(command)
        str = " %d " % data[3][2]
        db.commit()
        return str