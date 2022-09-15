#!/usr/bin/python3
"""
prints the State object with the name passed as argument from the database
"""
from model_state import Base, State
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
import sys

if __name__ == "__main__":
    engine = create_engine("mysql+mysqldb://{}:{}@localhost/{}".format(
                          sys.argv[1], sys.argv[2], sys.argv[3]))
    Session = sessionmaker(bind=engine)
    session = Session()
    try:
        states = session.query(State)\
                        .filter(State.name == "{}".format(sys.argv[4]))\
                        .first()
        print(states.id)
    except AttributeError:
        print("Not found")
