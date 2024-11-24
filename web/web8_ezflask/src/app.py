from flask import Flask
from flask import request
from flask import render_template_string
import re

app = Flask(__name__)
@app.route('/')
def app_index():
    name = request.args.get('name')
    if name:
        if re.search(r"2|3",name,re.I):
            return ':('
    template = '''
{%% block body %%}
    <div class="center-content error">
        <h1>Hello</h1>
        <h3>%s</h3>
    </div> 
{%% endblock %%}
''' % (request.args.get('name'))
    return render_template_string(template)

if __name__=="__main__":
    app.run(host='0.0.0.0',port=80)
    