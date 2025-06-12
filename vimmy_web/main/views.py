from django.shortcuts import render
# Create your views here.

def index(request):
    data = {
        'title': 'Main page',
    }
    return render(request, 'main/index.html', data)

def about(request):
    return render(request, 'main/about.html')

def func(request):
    print('hello')
    data = {
        'title': 'Main page',
    }
    return render(request, 'main/index.html', data)