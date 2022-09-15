#!/usr/bin/python3
"""
 lists all cities from the database hbtn_0e_4_usa
"""
import MySQLdb
import sys

if __name__ == "__main__":
    db = MySQLdb.connect(host="localhost", user=sys.argv[1],
                         passwd=sys.argv[2], db=sys.argv[3], port=3306)
    myCursor = db.cursor()
    myCursor.execute("SELECT cities.id, cities.name, states.name FROM cities\
                    LEFT JOIN states ON  states.id = cities.state_id  ORDER BY\
                    cities.id ASC")
    rows = myCursor.fetchall()
    for row in rows:
        print(row)
    myCursor.close()
    db.close()
