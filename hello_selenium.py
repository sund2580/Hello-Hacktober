#!/usr/bin/python3
from selenium import webdriver

def hello_world():
	browser = webdriver.Firefox()
	browser.get('https://www.helloworld.com/')
	browser.quit()
	

hello_world()
