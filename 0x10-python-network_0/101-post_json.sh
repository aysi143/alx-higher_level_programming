#!/bin/bash
# sends a JSON POST req to URL $!, display response body
curl -sL -H "content-type:application/json"  -d @"$2" -X POST "$1"
