# E-Commerce-OOP-System

A C++ object-oriented e-commerce system that demonstrates core OOP principles including inheritance, encapsulation, abstraction, and polymorphism. The system manages products, customers, shopping carts, and shipping services with expiration date tracking.

## Output

<div align="center">
    <img src="assets/output1.png" alt="code output">
    <img src="assets/output2.png" alt="code output">
</div>


## Run Locally

The project is already built and ready to run. Simply navigate to the project directory and execute the compiled binary:

```bash
./cmake-build-debug/code.exe
```

### Alternative (IDE)

If using an IDE like CLion or Visual Studio, simply open the project and run the main configuration.

## Design Choice

The system follows object-oriented design principles with the following key classes:

- `Store`: Central management class that handles products, customers, and shipping services. Maintains a product catalog and coordinates transactions.

- `Customer`: Represents system users with balance management and shopping cart functionality. Can add items to cart and checkout.

- `Product`: Core entity inheriting from ShippingItem. Contains product information including name, price, quantity, shipping details, and expiration information.

- `CartItem`: Links products with quantities in a customer's shopping cart, managing the relationship between customers and their selected products.

- `ShippingService`: Handles shipping logistics, calculates fees based on weight, and manages shipping items with their quantities.

- `ShippingItem`: Abstract base class providing polymorphic interface for shippable items with name and weight properties.

- `ShippingInfo`: Contains shipping-related data, primarily weight information for shipping cost calculations.

- `ExpirationInfo`: Manages product expiration dates and provides expiry checking functionality using the Date class.

- `Date`: Utility class for date operations, supporting day/month/year management and string representation.

The design uses inheritance (Product extends ShippingItem), composition (Product contains ShippingInfo and ExpirationInfo), and encapsulation with private data members and public interfaces.
