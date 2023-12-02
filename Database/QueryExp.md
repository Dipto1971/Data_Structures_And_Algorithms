Certainly! Let's go through each problem, explaining why the queries are written the way they are, the answers (code) according to the objectives, a breakdown of each sub-code (query within a query), and the table creation.

### Problem 1:

#### Objective:

Find all customer-related information who have an account in a branch located in the same city as where they live.

#### Explanation:

This query retrieves customer information for those who have an account in a branch in the same city as their residence. It involves joining the `Customer`, `Branch`, `Depositor`, and `Account` tables.

#### Answer (Code):

```sql
SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
FROM Customer C, Branch B, Depositor D, Account A
WHERE C.customer_name = D.customer_name
  AND A.account_number = D.account_number
  AND C.customer_city = B.branch_city;
```

#### Sub-Codes Explanation:

- The query involves multiple tables: `Customer`, `Branch`, `Depositor`, and `Account`.
- It uses the `WHERE` clause to specify conditions for joining these tables based on customer names, account numbers, and matching branch cities.
- `DISTINCT` ensures that only unique customer information is retrieved.

#### Table Creation:

```sql
CREATE TABLE Customer (
  customer_name VARCHAR(255),
  customer_street VARCHAR(255),
  customer_city VARCHAR(255)
);

CREATE TABLE Branch (
  branch_name VARCHAR(255),
  branch_city VARCHAR(255),
  assets DECIMAL(10, 2)
);

CREATE TABLE Account (
  account_number INT,
  branch_name VARCHAR(255),
  balance DECIMAL(10, 2)
);

CREATE TABLE Depositor (
  customer_name VARCHAR(255),
  account_number INT
);
```

### Problem 2:

#### Objective:

Find all customer-related information who have a loan in a branch located in the same city as where they live.

#### Explanation:

This query is similar to Problem 1 but involves customers with loans instead of accounts.

#### Answer (Code):

```sql
SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
FROM Customer C, Branch B, Loan L, Borrower Br
WHERE C.customer_name = Br.customer_name
  AND L.branch_name = B.branch_name
  AND C.customer_city = B.branch_city;
```

#### Sub-Codes Explanation:

- Similar to Problem 1 but involves the `Loan` and `Borrower` tables.
- Conditions are specified in the `WHERE` clause to match customer names, branch names, and cities.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 3:

#### Objective:

For each branch city, find the average balance of all the accounts opened in a branch located in that branch city. Do not include any branch city in the result where the total balance of all accounts opened in a branch located in that city is less than 1000.

#### Explanation:

This query calculates the average balance for each branch city and excludes cities where the total balance is less than 1000.

#### Answer (Code):

```sql
SELECT B.branch_city, AVG(A.balance) AS Avg_balance
FROM Branch B, Account A
WHERE A.branch_name = B.branch_name
GROUP BY B.branch_city
HAVING SUM(A.balance) > 1000;
```

#### Sub-Codes Explanation:

- Involves the `Branch` and `Account` tables.
- Uses the `GROUP BY` clause to group results by branch city.
- `HAVING` clause filters out cities where the total balance is less than 1000.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 4:

#### Objective:

For each branch city, find the average amount of all the loans opened in a branch located in that branch city. Do not include any branch city in the result where the average amount of all loans opened in a branch located in that city is less than 1500.

#### Explanation:

Similar to Problem 3 but involves the `Loan` table and calculates the average loan amount.

#### Answer (Code):

```sql
SELECT DISTINCT branch_city, AVG(amount) AS Avg_amount
FROM Branch B, Loan L
WHERE B.branch_name = L.branch_name
GROUP BY branch_city
HAVING AVG(amount) > 1500;
```

#### Sub-Codes Explanation:

- Involves the `Branch` and `Loan` tables.
- Uses the `GROUP BY` clause to group results by branch city.
- `HAVING` clause filters out cities where the average loan amount is less than 1500.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 5:

#### Objective:

Find the customer name, customer street, customer city of the account which has the highest balance among all the accounts.

#### Explanation:

This query identifies the customer details for the account with the highest balance.

#### Answer (Code):

```sql
SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
FROM Customer C, Account A, Depositor D
WHERE C.customer_name = D.customer_name
  AND A.account_number = D.account_number
  AND A.balance >= ALL (SELECT balance FROM Account);
```

#### Sub-Codes Explanation:

- Involves the `Customer`, `Account`, and `Depositor` tables.
- Uses the `ALL` keyword to compare the balance of each account with the maximum balance.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 6:

#### Objective:

Find the customer name, customer street, customer city of the loan which has the lowest amount among all the loans.

#### Explanation:

Similar to Problem 5 but involves the `Loan` table and identifies the customer details for the loan with the lowest amount.

#### Answer (Code):

```sql
SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
FROM Customer C, Loan L, Borrower Br
WHERE C.customer_name = Br.customer_name
  AND L.loan_number = Br.loan_number
  AND L.amount <= ALL (SELECT amount FROM Loan);
```

#### Sub-Codes Explanation:

- Involves the `Customer`, `Loan`, and `Borrower` tables.
- Uses the `ALL` keyword to compare the amount of each loan with the minimum amount.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 7:

#### Objective:

Find the distinct branches (name and city) that have opened both accounts and loans.

#### Explanation:

This query identifies branches that have both accounts and loans, using the `IN` and `EXISTS` keywords.

#### Answer (Code):

```sql
-- With IN keyword
SELECT DISTINCT B.branch_name, B.branch_city
FROM Branch B, Account A
WHERE B.branch_name = A.branch_name
  AND B.branch_name IN (SELECT DISTINCT B.branch_name FROM Branch B, Loan L WHERE A.branch_name = L.branch_name);

-- With EXISTS keyword
SELECT DISTINCT B.branch_name, B.branch_city
FROM Branch B, Account A
WHERE B.branch_name = A.branch_name
  AND EXISTS (SELECT * FROM Branch B1, Loan L WHERE A.branch_name = L.branch_name);
```

#### Sub-Codes Explanation:

- Involves the `Branch`, `Account`, and `Loan` tables.
- The first query uses the

`IN` keyword to check if the branch name is in the subquery's list of branch names with loans.

- The second query uses the `EXISTS` keyword to check if there's at least one row in the subquery for each row in the outer query.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 8:

#### Objective:

Find the distinct customers (name and city) who do not have loans but have accounts.

#### Explanation:

This query identifies customers without loans but with accounts, using the `NOT IN` and `NOT EXISTS` keywords.

#### Answer (Code):

```sql
-- With NOT IN keyword
SELECT DISTINCT C.customer_name, C.customer_city
FROM Customer C, Depositor D
WHERE C.customer_name = D.customer_name
  AND C.customer_name NOT IN (SELECT C.customer_name FROM Customer C, Borrower Br WHERE C.customer_name = Br.customer_name);

-- With NOT EXISTS keyword
SELECT DISTINCT C.customer_name, C.customer_city
FROM Customer C, Depositor D
WHERE C.customer_name = D.customer_name
  AND NOT EXISTS (SELECT * FROM Customer C1, Borrower B WHERE C.customer_name = B.customer_name);
```

#### Sub-Codes Explanation:

- Involves the `Customer`, `Depositor`, and `Borrower` tables.
- The first query uses the `NOT IN` keyword to exclude customers with loans from the subquery.
- The second query uses the `NOT EXISTS` keyword to check if there's no row in the subquery for each row in the outer query.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 9:

#### Objective:

Find those branch names which have a total account balance greater than the average of the total balance among all the branches.

#### Explanation:

This query identifies branches with a total account balance greater than the average of total balances, using the `WITH` clause.

#### Answer (Code):

```sql
WITH BranchBalances AS (
  SELECT B.branch_name, SUM(A.balance) AS TotalBalance
  FROM Branch B, Account A
  WHERE A.branch_name = B.branch_name
  GROUP BY B.branch_name
)
SELECT branch_name
FROM BranchBalances
WHERE TotalBalance > (SELECT AVG(TotalBalance) FROM BranchBalances);
```

#### Sub-Codes Explanation:

- Involves the `Branch` and `Account` tables.
- The `WITH` clause creates a temporary table (`BranchBalances`) with branch names and their total balances.
- The main query compares each branch's total balance with the average total balance.

#### Table Creation:

Use the same table creation commands as in Problem 1.

### Problem 10:

#### Objective:

Find those branch names which have a total loan amount less than the average of the total loan amount among all the branches.

#### Explanation:

Similar to Problem 9 but involves the `Loan` table and identifies branches with a total loan amount less than the average.

#### Answer (Code):

```sql
WITH BranchLoans AS (
  SELECT B.branch_name, SUM(L.amount) AS TotalLoanAmount
  FROM Branch B, Loan L
  WHERE L.branch_name = B.branch_name
  GROUP BY B.branch_name
)
SELECT branch_name
FROM BranchLoans
WHERE TotalLoanAmount < (SELECT AVG(TotalLoanAmount) FROM BranchLoans);
```

#### Sub-Codes Explanation:

- Involves the `Branch` and `Loan` tables.
- The `WITH` clause creates a temporary table (`BranchLoans`) with branch names and their total loan amounts.
- The main query compares each branch's total loan amount with the average total loan amount.

#### Table Creation:

Use the same table creation commands as in Problem 1.

These explanations provide a detailed understanding of each problem, the corresponding queries, and their components. If you have any specific questions about a particular query or concept, feel free to ask!
