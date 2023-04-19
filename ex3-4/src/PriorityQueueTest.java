import java.util.Comparator;

public class PriorityQueueTest {
    public static void main(String[] args){
        System.out.println("Inserimento valori int in pq");
        GenericPriorityQueue<Integer> pq = new GenericPriorityQueue<Integer>(Comparator.naturalOrder());
        pq.push(5);
        pq.push(3);
        pq.push(2);
        pq.push(4);
        pq.push(1);
        System.out.println("Stampa valori in ordine decrescente");
        for(int i = 0; i < 5; i++){
            System.out.print(pq.top() + " ");
            pq.pop();
        }
        System.out.println("\n");

        System.out.println("Inserimento valori int in pq2");
        GenericPriorityQueue<Integer> pq2 = new GenericPriorityQueue<Integer>(Comparator.reverseOrder());
        pq2.push(5);
        pq2.push(3);
        pq2.push(2);
        pq2.push(4);
        pq2.push(1);
        System.out.println("Stampa valori in ordine crescente");
        for(int i = 0; i < 5; i++){
            System.out.print(pq2.top() + " ");
            pq2.pop();
        }
        System.out.println("\n");

        System.out.println("\nInserimento valori int in pq3");
        GenericPriorityQueue<String> pq3 = new GenericPriorityQueue<String>(Comparator.naturalOrder());
        pq3.push("ciao");
        pq3.push("come");
        pq3.push("stai");
        pq3.push("tu");
        pq3.push("io");
        System.out.println("Stampa valori in ordine decrescente");
        for(int i = 0; i < 5; i++){
            System.out.print(pq3.top() + " ");
            pq3.pop();
        }
        System.out.println("\n");

        System.out.println("\nInserimento valori int in pq4");
        GenericPriorityQueue<String> pq4 = new GenericPriorityQueue<String>(Comparator.reverseOrder());
        pq4.push("ciao");
        pq4.push("come");
        pq4.push("stai");
        pq4.push("tu");
        pq4.push("io");
        System.out.println("Stampa valori in ordine crescente");
        for(int i = 0; i < 5; i++){
            System.out.print(pq4.top() + " ");
            pq4.pop();
        }
        System.out.println("\n");
    }
}