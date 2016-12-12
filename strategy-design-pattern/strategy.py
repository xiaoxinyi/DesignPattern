import abc


class Animal(object):

    def __init__(self):
        pass


    def set_height(self, new_height):
        self.__height = new_height

    def get_height(self):
        return self.__height

    def set_name(self, new_name):
        self.__name = new_name

    def get_name(self):
        return self.__name

    def set_weight(self, new_weight):
        if new_weight > 0:
            self.__weight = new_weight
        else:
            print 'weight must be bigger than 0'

    def get_weight(self):
        return self.__weight

    def set_fav_food(self, new_fav_food):
        self.__fav_food = new_fav_food

    def get_fav_food(self):
        return self.__fav_food

    def set_speed(self, new_speed):
        self.__speed = new_speed

    def set_sound(self, new_sound):
        self.__sound = new_sound

    def set_fly_type(self, new_fly_type):
        self.fly_type = new_fly_type

    def try_to_fly(self):
        return self.fly_type.fly()


class Dog(Animal):
    def __init__(self):
        Animal.__init__(self)
        self.set_sound("Bark")
        self.fly_type = CantFly()

    def dig_hole(self):
        print 'Dug a hole'


class Bird(Animal):
    def __init__(self):
        Animal.__init__(self)
        self.set_sound("Tweet")
        self.fly_type = ItFlys()


class Flys(object):
    __metaclass__ = abc.ABCMeta

    @abc.abstractmethod
    def fly(self):
        return


class CantFly(Flys):
    def fly(self):
        return 'I can\'t fly'


class ItFlys(Flys):
    def fly(self):
        return 'Flying High'


if __name__ == '__main__':
    sparky = Dog()
    tweety = Bird()

    print 'Dog: {}'.format(sparky.try_to_fly())
    print 'Bird: {}'.format(tweety.try_to_fly())

    sparky.set_fly_type(ItFlys())
    print 'Dog: {}'.format(sparky.try_to_fly())
