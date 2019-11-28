import MySQLdb
class DB:
    conn = None

    def connect(self):
        self.conn = MySQLdb.connect(
            host="phoudor11122.mysql.pythonanywhere-services.com", user="phoudor11122", passwd="fe3rFGtg5", db="phoudor11122$default"
        )

    def commit(self):
        self.conn.commit()

    def query(self, sql):
        try:
            cursor = self.conn.cursor()
            cursor.execute(sql)
        except (AttributeError, MySQLdb.OperationalError):
            self.connect()
            cursor = self.conn.cursor()
            cursor.execute(sql)
        return cursor.fetchall()
    def query2(self, sql):
        cursor = self.conn.cursor()
        cursor.execute(sql)
        return cursor.fetchone()
