# SuperMarket Online Shopping System GUI Using Qt

The SuperMarket Online Shopping Project is a desktop application that enables users to purchase products and provide ratings. The application is divided into two main components: a Seller part and a Buyer part. Sellers can add and manage their products, while buyers can browse and buy products, and provide ratings for them.

The application is built using Qt and C++ , mysql database and incorporates structured programming concepts and OOP principles to efficiently manage user interactions and product information.

## Features
- Sellers can easily add and manage their products, ensuring their inventory is always up-to-date.
- Buyers can browse and purchase a wide range of products with ease.
- Buyers can rate products only after purchase, ensuring genuine feedback.
- Buyers can enjoy special discounts through a coupon system.
- Buyers can view their previous orders and track their purchase history.
- Buyers can explore all sellers and their product offerings.
- Buyers can subscribe to their favorite sellers for updates and new product alerts.
- Buyers can search for products by name with autocomplete suggestions.
- All data is saved in a MySQL database, so if the program is closed and reopened, the data remains saved.

## Installation
The News Management Project is a desktop application that requires QT and C++ to run. Follow the steps below to install and run the application:

1. Clone the repository to your local machine.
2. Open the project using QT Creator.
3. Build and run the application.

## Usage

### Seller part

The seller functions of the application allows seller to add products. Here are the steps to use the seller functionality:

- **Create Account:** Click "Create Seller account". 
    - Password must be greater than 8 characters.
    - Phone number must be 11 digits.
    - Email must contain "@" and a period. 
    - It's a must to accept the policy.
    - upload your image (Optional) 

- **Login** with your Created Account. 

- **Forget Password:**
    - Enter your ID, email, and username for verification.

- **Change Profile Information:**
    - You can change name, email, username, and phone number (except ID).

- **Add New Product:**
    - Enter name, category (must be from the seven categories in the system), price, stock, image, expiration date (for some categories).

- **View and Restock Products:** View the products added by this seller and restock them.

### Buyer part

The buyer functions of the application allow buyers to purchase products and interact with them. Here are the steps to use the buyer functionality:

- **Create Account:** Click "Register" in Buyer part. 
    - Enter full name, email, password, phone number, and location (where products will be shipped).
    - No duplicate emails (buyer and seller can't have the same email).

- **Login** with your created account.

- **Forget Passsword**
    - Enter your ID and email for verification. 

- **Modify Profile Information:** 
    - You can change name, email, username, and phone number (except ID).

- **Search for Products:** Search for products by name with autocomplete functionality.

- **Dashboard Page:**
    - Displays top-rated products and random products for you.
    - Add any product to the cart.

- **Categories Page:**
    - The system has 7 categories: Groceries, Electronics, Video Games, Office, Beauty, Sports Supplies, and Home Furniture.
    - Clicking on a category displays its products with details (ID, Name, Seller Name, Price, Rating, Quantity).
    - Add any product to the cart.

- **Sellers Page:**
    - View all sellers in the system.
    - View the products of each seller.
    - Subscribe to sellers.

- **Cart Page:**
    - View and modify the quantity of products in the cart.
    - Checkout and pay using Visa, PayPal, or cash on delivery.
    - For Visa: enter credit card number, CVV, expiration month, and year.
    - For PayPal: enter email.

- **Orders History:** 
    - View previously purchased products.
    - Rate purchased products.


- **Coupons Page:**
    - A game-like feature where you choose one of 4 boxes to win a coupon.
    - Use coupons at cart to subtract their value from the product price while checkout.

