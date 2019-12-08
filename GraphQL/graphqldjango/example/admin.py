from django.contrib import admin

# Register your models here.
from .models import Category, Ingredient

admin.site.register(Category)
admin.site.register(Ingredient)