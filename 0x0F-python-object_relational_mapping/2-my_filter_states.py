#!/usr/bin/python3
"""
takes in an argument and displays all values in the states table
"""
import MySQLdb
import sys

if __name__ == "__main__":
    db = MySQLdb.connect(host="localhost", user=sys.argv[1],
                         passwd=sys.argv[2], db=sys.argv[3], port=3306)
    match = sys.argv[4]
    myCursor = db.cursor()
    myCursor.execute("SELECT * FROM states WHERE name LIKE BINARY '{}'\
                     ORDER BY states.id ASC".format(sys.argv[4]))
    rows = myCursor.fetchall()
    for row in rows:
        print(row)
    myCursor.close()
    db.close()
