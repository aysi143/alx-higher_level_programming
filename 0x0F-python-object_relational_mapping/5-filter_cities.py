#!/usr/bin/python3
"""
takes in the name of a state as an argument and lists all cities of that state
"""
import MySQLdb
import sys

if __name__ == "__main__":
    db = MySQLdb.connect(host="localhost", user=sys.argv[1],
                         passwd=sys.argv[2], db=sys.argv[3], port=3306)
    match = sys.argv[4]
    myCursor = db.cursor()
    myCursor.execute("SELECT cities.name FROM cities WHERE cities.state_id\
                     = (SELECT states.id FROM states WHERE states.name = '{}'\
                     LIMIT 1) ORDER BY cities.id".format(match))
    rows = myCursor.fetchall()
    new_list = []
    for row in rows:
        new_list.append(row[0])
    print(", ".join(new_list))
    myCursor.close()
    db.close()
