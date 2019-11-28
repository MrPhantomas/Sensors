import command_system
import Db
def sens_data():
    db = Db.DB()
    command = 'select * from sensors_data order by sensors_data_id desc limit 1'
    data = db.query(command)
    message = ''
    mass = []
    for x in data[0]:
        mass.append(int(x))
    if mass[1] > 83 or mass[2] > 10600 or mass[3] > 166 or mass[5] > 70 :
        message += 'ВНИМАНИЕ!! ПРЕВЫШЕНО ПДК!\n (на одном или нескольких из значений/ях датчиков)\n\n'
    message += 'Бутан -  %d  ppm (ПДК - 83 ppm)\n' % mass[1]
    message += 'Метан - %d ppm (ПДК - 10600 ppm)\n' % mass[2]
    message += 'Пропан - %d ppm (ПДК - 166 ppm)\n' % mass[3]
    message += 'Водород - %d ppm\n' % mass[4]
    message += 'Температура - %d  с\n' % mass[5]
    db.commit()
    return message, ''


info_command = command_system.Command()

info_command.keys = ['данные датчиков', 'датчик', 'пропан', 'бутан', 'метан', 'водород', 'температура']
info_command.description = 'Покажу данные датчиков'
info_command.process = sens_data