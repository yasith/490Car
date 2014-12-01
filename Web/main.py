#!/usr/bin/env python

import webapp2
import jinja2
import os
import cgi

jinja_environment = jinja2.Environment(
    loader=jinja2.FileSystemLoader(os.path.dirname(__file__)))

class MainHandler(webapp2.RequestHandler):
  def get(self):
    template_values = {}

    template = jinja_environment.get_template('index.html')
    self.response.out.write(template.render(template_values))

app = webapp2.WSGIApplication([
    ('/', MainHandler)
], debug=True)
