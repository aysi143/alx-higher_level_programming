#!/usr/bin/python3
"""
 lists all State objects that contain the letter a from the database
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
    states = session.query(State)\
                    .filter(State.name.like('%a%'))\
                    .order_by(State.id.asc())
    for state in states:
        print("{}: {}".format(state.id, state.name))
    session.close()
