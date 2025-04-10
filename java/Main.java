class Animal {
    public void animalSound() {
        System.out.println("Animal makes a sound");
    }
}

class Pig extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The pig says: wee wee");
    }
}

class Dog extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The dog says: bow bow");
    }
}

public class Main {
    public static void main(String[] args) {
        Animal[] animals = {new Animal(), new Pig(), new Dog()};
        for (Animal animal : animals) {
            animal.animalSound();
        }
    }
}
