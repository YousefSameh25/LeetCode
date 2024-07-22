public class ParkingSystem {

    private int[] Types;

    public ParkingSystem(int big, int medium, int small) {
        Types = new int[3];
        Types[0] = big;
        Types[1] = medium;
        Types[2] = small;
    }
    
    public bool AddCar(int carType) {
        if (Types[carType - 1] <= 0)
            return false;

        Types[carType - 1]--;
        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj.AddCar(carType);
 */