import sys
import time

# ========================================
# MODULE A: MIN-HEAP (The Priority Processor)
# ========================================
class MinHeap:
    def __init__(self):
        self.heap = []

    def insert(self, priority, patient_name):
        self.heap.append((priority, patient_name))
        self._heapify_up(len(self.heap) - 1)
        print(f"  [Heap] ✅ Added: {patient_name} (Priority {priority})")

    def _heapify_up(self, index):
        parent = (index - 1) // 2
        if index > 0 and self.heap[index][0] < self.heap[parent][0]:
            self.heap[index], self.heap[parent] = self.heap[parent], self.heap[index]
            self._heapify_up(parent)

    def extract_min(self):
        if len(self.heap) == 0: return None
        if len(self.heap) == 1: return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify_down(0)
        return root

    def _heapify_down(self, index):
        smallest = index
        left = 2 * index + 1
        right = 2 * index + 2
        if left < len(self.heap) and self.heap[left][0] < self.heap[smallest][0]:
            smallest = left
        if right < len(self.heap) and self.heap[right][0] < self.heap[smallest][0]:
            smallest = right
        if smallest != index:
            self.heap[index], self.heap[smallest] = self.heap[smallest], self.heap[index]
            self._heapify_down(smallest)

    def is_empty(self): return len(self.heap) == 0
    def size(self): return len(self.heap)

# ========================================
# MODULE B: HASH TABLE (The Rapid Registry)
# ========================================
class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]
        self.count = 0

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                print(f"  [Hash] 🔄 Updated record for {key}")
                return
        self.table[index].append((key, value))
        self.count += 1
        print(f"  [Hash] 💾 Saved record for {key}")

    def get(self, key):
        index = self._hash(key)
        for k, v in self.table[index]:
            if k == key: return v
        return None

# ========================================
# MODULE C: GRAPH (Connectivity Network)
# ========================================
class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v, w):
        if u not in self.graph: self.graph[u] = []
        if v not in self.graph: self.graph[v] = []
        self.graph[u].append((v, w))
        self.graph[v].append((u, w))

    def dijkstra(self, start, end):
        if start not in self.graph or end not in self.graph:
            return [], float('infinity')
            
        distances = {vertex: float('infinity') for vertex in self.graph}
        distances[start] = 0
        previous = {vertex: None for vertex in self.graph}
        unvisited = list(self.graph.keys())

        while unvisited:
            current = min(unvisited, key=lambda vertex: distances[vertex])
            if distances[current] == float('infinity') or current == end:
                break
            unvisited.remove(current)

            for neighbor, weight in self.graph[current]:
                if neighbor in unvisited: # Optimization check
                    distance = distances[current] + weight
                    if distance < distances[neighbor]:
                        distances[neighbor] = distance
                        previous[neighbor] = current

        path = []
        current = end
        while current is not None:
            path.insert(0, current)
            current = previous[current]
        
        return (path, distances[end]) if path[0] == start else ([], float('infinity'))

# ========================================
# MODULE D: BST (Organized Archive)
# ========================================
class TreeNode:
    def __init__(self, key, value):
        self.key, self.value, self.left, self.right = key, value, None, None

class BinarySearchTree:
    def __init__(self): self.root = None

    def insert(self, key, value):
        if not self.root: self.root = TreeNode(key, value)
        else: self._insert_rec(self.root, key, value)

    def _insert_rec(self, node, key, value):
        if key < node.key:
            if node.left: self._insert_rec(node.left, key, value)
            else: node.left = TreeNode(key, value)
        else:
            if node.right: self._insert_rec(node.right, key, value)
            else: node.right = TreeNode(key, value)

    def inorder(self):
        res = []
        self._inorder_rec(self.root, res)
        return res

    def _inorder_rec(self, node, res):
        if node:
            self._inorder_rec(node.left, res)
            res.append((node.key, node.value))
            self._inorder_rec(node.right, res)

# ========================================
# INTERACTIVE DRIVER CODE
# ========================================
def clear_screen():
    print("\n" * 2) # Simple spacer instead of os.system('cls') for compatibility

def print_menu():
    print("\n" + "="*50)
    print("   🏥 HOSPITAL EMERGENCY SYSTEM (MAIN MENU)")
    print("="*50)
    print(" 1. [Module A] Add Emergency Patient (Min-Heap)")
    print(" 2. [Module A] Treat/Process Next Patient")
    print(" 3. [Module B] Search Patient Details (Hash Table)")
    print(" 4. [Module C] Find Hospital Route (Graph)")
    print(" 5. [Module D] View Visit History (BST Sorted)")
    print(" 6. Populate Dummy Data (For Testing)")
    print(" 0. Exit")
    print("="*50)

def main():
    # Initialize Systems
    er_queue = MinHeap()
    registry = HashTable()
    hospital_map = Graph()
    archive = BinarySearchTree()

    # Pre-build the map (Static infrastructure)
    hospital_map.add_edge("ER", "Lobby", 10)
    hospital_map.add_edge("ER", "ICU", 50)
    hospital_map.add_edge("Lobby", "Pharmacy", 20)
    hospital_map.add_edge("ICU", "Surgery", 15)
    hospital_map.add_edge("Pharmacy", "Surgery", 40)
    hospital_map.add_edge("Surgery", "Ward", 30)

    while True:
        print_menu()
        choice = input(" Select an option (0-6): ").strip()

        if choice == '1':
            print("\n--- 🚑 Add New Patient ---")
            name = input(" Enter Name: ")
            try:
                print(" Priority Levels: 1=Critical(Heart Attack), 5=Minor(Cold)")
                prio = int(input(" Enter Priority (1-5): "))
                er_queue.insert(prio, name)
            except ValueError:
                print(" ❌ Error: Priority must be a number.")

        elif choice == '2':
            print("\n--- 👨‍⚕️ Treatment Room ---")
            if er_queue.is_empty():
                print(" No patients waiting! Relax.")
            else:
                prio, name = er_queue.extract_min()
                print(f" 🔔 NOW TREATING: {name}")
                print(f"    Condition Severity: {prio}")
                # Auto-archive the visit
                import random
                visit_id = random.randint(100, 999)
                archive.insert(visit_id, f"Treated {name} (P{prio})")
                print(f"    (Log saved to Archive ID: {visit_id})")

        elif choice == '3':
            print("\n--- 🔍 Registry Search ---")
            pid = input(" Enter Patient ID (e.g., P001): ")
            record = registry.get(pid)
            if record:
                print(f" 📄 FOUND: {record}")
            else:
                print(" ❌ Record not found.")

        elif choice == '4':
            print("\n--- 🗺️ Navigation System ---")
            print(" Locations: ER, Lobby, ICU, Surgery, Pharmacy, Ward")
            start = input(" Start Location: ")
            end = input(" Destination: ")
            path, dist = hospital_map.dijkstra(start, end)
            if dist == float('infinity'):
                print(" ❌ No path found (Check spelling!).")
            else:
                print(f" ✅ Shortest Path: {' -> '.join(path)}")
                print(f" 🏃 Total Distance: {dist} meters")

        elif choice == '5':
            print("\n--- 📂 Patient History Archive ---")
            history = archive.inorder()
            if not history:
                print(" Archive is empty.")
            else:
                print(" ID  | Record Description")
                print(" ----|-------------------")
                for pid, rec in history:
                    print(f" {pid} | {rec}")

        elif choice == '6':
            print("\n--- ⚙️ Loading Dummy Data ---")
            er_queue.insert(1, "Ahmed (Heart Attack)")
            er_queue.insert(4, "Ayesha (Sprained Ankle)")
            registry.insert("P001", "Ahmed - O+")
            registry.insert("P002", "Ayesha - A-")
            archive.insert(101, "Old visit: Ahmed checkup")
            print(" Done! Systems populated.")

        elif choice == '0':
            print(" Exiting Simulation. Goodbye!")
            break

        else:
            print(" ❌ Invalid option.")
        
        input("\nPress Enter to continue...")
        clear_screen()

if __name__ == "__main__":
    main()