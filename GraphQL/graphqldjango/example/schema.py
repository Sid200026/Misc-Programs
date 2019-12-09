# import graphene
# from graphene_django.types import DjangoObjectType
# from .models import Category, Ingredient

# class CategoryType(DjangoObjectType):
#     class Meta:
#         model = Category

# class IngredientType(DjangoObjectType):
#     class Meta:
#         model = Ingredient


# class Query(object):
#     all_categories = graphene.List(CategoryType)
#     all_ingredients = graphene.List(IngredientType)
#     ingredient = graphene.Field(
#         IngredientType,
#         name=graphene.String(),
#         id=graphene.ID(),
#     )
#     category = graphene.Field(
#         CategoryType,
#         name = graphene.String(),
#         id=graphene.ID(),
#     )
#     count_category = graphene.List(CategoryType, first=graphene.Int())
#     category_contains = graphene.List(CategoryType, word=graphene.String())
#     category_exact = graphene.List(CategoryType, word=graphene.String())
#     ingredient_endsWith = graphene.List(IngredientType, word=graphene.String())

#     def resolve_ingredient_endsWith(self, info, **kwargs):
#         word = kwargs.get('word')
#         return Ingredient.objects.filter(name__endswith=word)

#     def resolve_category_exact(self, info, **kwargs):
#         word = kwargs.get('word')
#         return Category.objects.filter(name__exact=word)

#     def resolve_category_contains(self, info, **kwargs):
#         word = kwargs.get('word')
#         return Category.objects.filter(name__icontains=word)

#     def resolve_all_categories(self, info, **kwargs):
#         return Category.objects.all()
    
#     def resolve_all_ingredients(self, info, **kwargs):
#         return Ingredient.objects.all()

#     def resolve_ingredient(self, info, **kwargs):
#         name = kwargs.get('name')
#         id = kwargs.get('id')
#         if id is not None:
#             return Ingredient.objects.get(pk=id)
#         if name is not None:
#             return Ingredient.objects.get(name=name)
#         return None

#     def resolve_category(self, info, **kwargs):
#         name = kwargs.get('name')
#         id = kwargs.get('id')
#         if id is not None:
#             return Category.objects.get(pk=id)
#         if name is not None:
#             return Category.objects.get(name=name)
#         return None

#     def resolve_count_category(self, info, **kwargs):
#         first = kwargs.get('first')
#         return Category.objects.all()[:first]

# class createCategoryType(graphene.Mutation):
#     class Arguments: # input for mutations
#         name = graphene.String()

#     category = graphene.Field(CategoryType) # Response of the mutation

#     def mutate(self, info, name):
#         if(not Category.objects.filter(name=name).exists):
#             temp = Category.objects.create(name=name)
#             temp.save()
#         else:
#             temp = Category.objects.get(name=name)
#         return createCategoryType(category=temp)

# class createIngredientType(graphene.Mutation):
#     class Arguments:
#         id = graphene.ID()
#         name = graphene.String()
#         notes = graphene.String()
    
#     ingredient = graphene.Field(IngredientType)

#     def mutate(self, info, id, name, notes):
#         category = Category.objects.get(pk=id)
#         temp = Ingredient.objects.create(category=category, name=name, notes=notes)
#         temp.save()

#         return createIngredientType(ingredient = temp)


# class ingredient_input(graphene.InputObjectType):
#     name=graphene.String(required=True)
#     notes=graphene.String(required=True)
#     catid = graphene.ID(required=True)

# class removeIngredient(graphene.Mutation):
#     class Arguments:
#         id = graphene.ID()
#     ingredients = graphene.Field(IngredientType)

#     def mutate(self, info, id):
#         ingredient = Ingredient.objects.get(pk=id)
#         ingredient.delete()
#         return removeIngredient(ingredient)

# class addNewIngredient(graphene.Mutation):
#     class Arguments:
#         ingredient = ingredient_input(required=True)
        
#     ingredient = graphene.Field(IngredientType)

#     def mutate(self, info, ingredient):
#         category = Category.objects.get(pk=ingredient.catid)
#         new_ing = Ingredient(name=ingredient.name, notes=ingredient.notes, category=category)
#         new_ing.save()
#         return addNewIngredient(ingredient=new_ing)

# class Mutation(graphene.ObjectType):
#     create_category = createCategoryType.Field()
#     create_ingredient = createIngredientType.Field()
#     remove_ingredient = removeIngredient.Field()
#     create_ingredient_2 = addNewIngredient.Field()


import graphene
from graphene_django.types import DjangoObjectType
from .models import Category, Ingredient
from django.contrib.auth.models import User
from graphql_jwt.decorators import login_required

class UserType(DjangoObjectType):
    class Meta:
        model = User



class createUser(graphene.Mutation):
    class Arguments:
        name = graphene.String(required = True)
        email = graphene.String(required = True)
        password = graphene.String(required = True)
    
    user = graphene.Field(UserType)

    def mutate(self, info, name, email, password):
        user = User.objects.create_user(username=name, email=email, password=password)
        user.save()
        return createUser(user)

class Mutation(graphene.ObjectType):
    add_user = createUser.Field()

class Query:
    getUsers = graphene.List(UserType)
    me = graphene.Field(UserType)

    def resolve_getUsers(self, info, **kwargs):
        return User.objects.all()

    @login_required
    def resolve_me(self, info, **kwargs):
        user = info.context.user
        if user.is_anonymous:
            raise Exception("Not logged in")
        return user