
import java.util.*;

class Employee {
 String name;
 int id;

 public Employee(String name, int id) {
     this.name = name;
     this.id = id;
 }

 public void work() {
     System.out.println(name + " is working.");
 }
}

class Worker extends Employee {
 Department department;

 public Worker(String name, int id, Department department) {
     super(name, id);
     this.department = department;
 }

 @Override
 public void work() {
     System.out.println(name + " (Worker) is processing sugarcane in " + department.deptName + " department.");
 }

 public String getDepartmentName() {
     return department.deptName;
 }
}

class Manager extends Employee {
 public Manager(String name, int id) {
     super(name, id);
 }

 @Override
 public void work() {
     System.out.println(name + " (Manager) is managing the factory.");
 }
}


class Machine {
 String machineId;

 public Machine(String machineId) {
     this.machineId = machineId;
 }

 public void operate() throws MachineFailureException {
     System.out.println("Machine " + machineId + " is operating.");
     if (new Random().nextInt(10) > 7) {
         throw new MachineFailureException("Machine " + machineId + " failed!");
     }
 }
}


class Department {
 String deptName;
 List<Machine> machines;

 public Department(String deptName) {
     this.deptName = deptName;
     this.machines = new ArrayList<>();
 }

 public void addMachine(Machine machine) {
     machines.add(machine);
 }

 public void runMachines() {
     for (Machine m : machines) {
         try {
             m.operate();
         } catch (MachineFailureException e) {
             System.out.println("⚠️ ERROR: " + e.getMessage());
         }
     }
 }
}

class Factory {
 String name;
 List<Department> departments;
 List<Worker> workers;
 double totalRevenue;
 double totalCosts;

 public Factory(String name) {
     this.name = name;
     this.departments = new ArrayList<>();
     this.workers = new ArrayList<>();
     this.totalRevenue = 0;
     this.totalCosts = 0;
 }

 public void addDepartment(Department dept) {
     departments.add(dept);
 }

 public void addWorker(Worker worker) {
     workers.add(worker);
 }

 public boolean removeWorkerById(int id) {
     for (int i = 0; i < workers.size(); i++) {
         if (workers.get(i).id == id) {
             workers.remove(i);
             System.out.println("👷 Worker with ID " + id + " removed from factory.");
             return true;
         }
     }
     System.out.println("❌ Worker with ID " + id + " not found in factory.");
     return false;
 }

 public int getWorkerCount() {
     return workers.size();
 }

 public void startProduction() {
     System.out.println("\n🔧 Production started at " + name);
     for (Department d : departments) {
         System.out.println("\n🔹 Running machines in " + d.deptName + " department...");
         d.runMachines();
     }
 }

 public void addRevenue(double amount) {
     totalRevenue += amount;
 }

 public void addCosts(double amount) {
     totalCosts += amount;
 }

 public double calculateProfitOrLoss() {
     return totalRevenue - totalCosts;
 }
}

class MachineFailureException extends Exception {
 public MachineFailureException(String message) {
     super(message);
 }
}


class ProductionThread extends Thread {
 Factory factory;

 public ProductionThread(Factory factory) {
     this.factory = factory;
 }

 @Override
 public void run() {
     factory.startProduction();
 }
}

class SugarBagInventory {
 private int totalBags;

 public SugarBagInventory() {
     this.totalBags = 0;
 }

 public void addBags(int count) {
     if (count > 0) {
         totalBags += count;
         System.out.println(count + " sugar bags added. ✅ Total now: " + totalBags);
     } else {
         System.out.println("❌ Invalid number of bags to add.");
     }
 }

 public void removeBags(int count) {
     if (count > 0 && count <= totalBags) {
         totalBags -= count;
         System.out.println(count + " sugar bags removed. ✅ Total now: " + totalBags);
     } else {
         System.out.println("❌ Cannot remove " + count + " bags. Not enough in inventory.");
     }
 }

 public int getTotalBags() {
     return totalBags;
 }
}


class Administration {
 private List<Employee> employeeRecords;

 public Administration() {
     employeeRecords = new ArrayList<>();
 }

 public void addEmployee(Employee e) {
     employeeRecords.add(e);
 }

 public boolean removeEmployeeById(int id) {
     for (int i = 0; i < employeeRecords.size(); i++) {
         if (employeeRecords.get(i).id == id) {
             employeeRecords.remove(i);
             System.out.println("🗂️ Employee with ID " + id + " removed from admin records.");
             return true;
         }
     }
     System.out.println("❌ Employee with ID " + id + " not found in admin records.");
     return false;
 }

 public void showAllEmployees() {
     System.out.println("\n📋 Administration Report: Employee List");
     for (Employee e : employeeRecords) {
         String deptName = (e instanceof Worker) ? ((Worker) e).getDepartmentName() : "N/A";
         System.out.println("👤 " + e.name + " (ID: " + e.id + ") - " + e.getClass().getSimpleName() + " | Department: " + deptName);
     }
 }

 public int getTotalEmployees() {
     return employeeRecords.size();
 }
}

public class SugarIndustryProject {
 public static void main(String[] args) {
     Scanner sc = new Scanner(System.in);

     System.out.print("Enter Factory Name: ");
     String factoryName = sc.nextLine();
     Factory sugarFactory = new Factory(factoryName);
     Administration admin = new Administration();

     int workerCount = readInt(sc, "\nHow many workers do you want to enroll? ");
     int deptCount = readInt(sc, "\nHow many departments do you want to add? ");

     for (int i = 0; i < deptCount; i++) {
         System.out.print("Enter Department " + (i + 1) + " Name: ");
         String deptName = sc.nextLine();
         Department dept = new Department(deptName);

         int machineCount = readInt(sc, "How many machines in " + deptName + "? ");
         for (int j = 0; j < machineCount; j++) {
             System.out.print("Enter Machine ID " + (j + 1) + ": ");
             String machineId = sc.nextLine();
             dept.addMachine(new Machine(machineId));
         }

         sugarFactory.addDepartment(dept);
     }

     for (int i = 0; i < workerCount; i++) {
         System.out.print("Enter Worker " + (i + 1) + " Name: ");
         String name = sc.nextLine();
         int workerId = readInt(sc, "Enter Worker " + (i + 1) + " ID: ");

         System.out.print("Assign Worker " + name + " to a department: ");
         String deptName = sc.nextLine();

         Department assignedDept = null;
         for (Department dept : sugarFactory.departments) {
             if (dept.deptName.equalsIgnoreCase(deptName)) {
                 assignedDept = dept;
                 break;
             }
         }

         if (assignedDept != null) {
             Worker worker = new Worker(name, workerId, assignedDept);
             sugarFactory.addWorker(worker);
             admin.addEmployee(worker);
             worker.work();
         } else {
             System.out.println("❌ Invalid department name. Worker not assigned.");
         }
     }

     System.out.print("\nEnter Manager Name: ");
     String managerName = sc.nextLine();
     int managerId = readInt(sc, "Enter Manager ID: ");

     Manager manager = new Manager(managerName, managerId);
     admin.addEmployee(manager);
     manager.work();

     ProductionThread production = new ProductionThread(sugarFactory);
     production.start();

     try {
         production.join();
     } catch (InterruptedException e) {
         e.printStackTrace();
     }

     System.out.println("\n💰 Profit or Loss Calculation:");
     double profitOrLoss = sugarFactory.calculateProfitOrLoss();
     if (profitOrLoss >= 0) {
         System.out.println("Profit: $" + profitOrLoss);
     } else {
         System.out.println("Loss: $" + Math.abs(profitOrLoss));
     }

     System.out.println("\n👷 Total number of workers enrolled: " + sugarFactory.getWorkerCount());

     SugarBagInventory inventory = new SugarBagInventory();
     boolean managingInventory = true;

     System.out.println("\n📦 Managing Sugar Bag Inventory:");

     while (managingInventory) {
         System.out.println("\nChoose an option:");
         System.out.println("1. Add sugar bags");
         System.out.println("2. Remove sugar bags");
         System.out.println("3. View total bags");
         System.out.println("4. Remove worker by ID");
         System.out.println("5. Exit");

         int choice = readInt(sc, "Enter choice: ");

         switch (choice) {
             case 1:
                 int add = readInt(sc, "How many bags to add? ");
                 inventory.addBags(add);
                 sugarFactory.addRevenue(add * 5);
                 break;
             case 2:
                 int remove = readInt(sc, "How many bags to remove? ");
                 inventory.removeBags(remove);
                 break;
             case 3:
                 System.out.println("📦 Total sugar bags in inventory: " + inventory.getTotalBags());
                 break;
             case 4:
                 int removeId = readInt(sc, "Enter Worker ID to remove: ");
                 sugarFactory.removeWorkerById(removeId);
                 admin.removeEmployeeById(removeId);
                 break;
             case 5:
                 managingInventory = false;
                 break;
             default:
                 System.out.println("❌ Invalid choice.");
         }
     }

     admin.showAllEmployees();
     System.out.println("👥 Total employees in the system: " + admin.getTotalEmployees());
     System.out.println("\n✅ Production and administration complete.");
     sc.close();
 }

 public static int readInt(Scanner sc, String prompt) {
     int number;
     while (true) {
         System.out.print(prompt);
         try {
             number = sc.nextInt();
             sc.nextLine();
             return number;
         } catch (InputMismatchException e) {
             System.out.println("❌ Invalid input! Please enter a valid number.");
             sc.nextLine();
         }
     }
 }
}
