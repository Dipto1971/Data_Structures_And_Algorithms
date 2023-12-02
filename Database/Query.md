Certainly! Here are the rewritten SQL queries along with the questions they answer:

1. **Find all customer related information who have an account in a branch located in the same city as where they live. (Without subquery and using subquery)**

   Without Subquery:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city, B.branch_city
   FROM Customer C, Branch B, Depositor D, Account A
   WHERE C.customer_name = D.customer_name
     AND A.account_number = D.account_number
     AND C.customer_city = B.branch_city;
   ```

   Using Subquery:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city, B.branch_city
   FROM Customer C
   JOIN Depositor D ON C.customer_name = D.customer_name
   JOIN Account A ON D.account_number = A.account_number
   JOIN Branch B ON A.branch_name = B.branch_name
   WHERE C.customer_city IN (SELECT DISTINCT branch_city FROM Branch);
   ```

   Question: Find all customers who have an account in a branch located in the same city as where they live.

2. **Find all customer related information who have a loan in a branch located in the same city as where they live. (Without subquery and using subquery)**

   Without Subquery:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city, B.branch_city
   FROM Customer C, Borrower Br, Loan L, Branch B
   WHERE C.customer_name = Br.customer_name
     AND Br.loan_number = L.loan_number
     AND L.branch_name = B.branch_name
     AND C.customer_city = B.branch_city;
   ```

   Using Subquery:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city, B.branch_city
   FROM Customer C
   JOIN Borrower Br ON C.customer_name = Br.customer_name
   JOIN Loan L ON Br.loan_number = L.loan_number
   JOIN Branch B ON L.branch_name = B.branch_name AND C.customer_city = B.branch_city;
   ```

   Question: Find all customers who have a loan in a branch located in the same city as where they live.

3. **For each branch city, find the average balance of all the accounts opened in a branch located in that branch city. Do not include any branch city in the result where the total balance of all accounts opened in a branch located in that city is less than 1000. (With and without using the 'HAVING' clause)**

   With HAVING Clause:

   ```sql
   SELECT B.branch_city, AVG(A.balance) AS Avg_balance
   FROM Branch B
   JOIN Account A ON A.branch_name = B.branch_name
   GROUP BY B.branch_city
   HAVING SUM(A.balance) > 1000;
   ```

   Without HAVING Clause:

   ```sql
   SELECT R1.branch_city, R1.Avg_balance
   FROM (
     SELECT branch_city, AVG(balance) AS Avg_balance
     FROM Account A, Branch B
     WHERE B.branch_name = A.branch_name
     GROUP BY branch_city
   ) R1
   JOIN (
     SELECT branch_city, SUM(balance) AS Total_balance
     FROM Account A, Branch B
     WHERE B.branch_name = A.branch_name
     GROUP BY branch_city
   ) R2 ON R1.branch_city = R2.branch_city
   WHERE R2.Total_balance > 1000;
   ```

   Question: For each branch city, find the average balance of accounts where the total balance is greater than 1000.

4. **For each branch city, find the average amount of all the loans opened in a branch located in that branch city. Do not include any branch city in the result where the average amount of all loans opened in a branch located in that city is less than 1500. (With and without using the 'HAVING' clause)**

   With HAVING Clause:

   ```sql
   SELECT DISTINCT branch_city, AVG(amount) AS Avg_amount
   FROM Branch B, Loan L
   WHERE B.branch_name = L.branch_name
   GROUP BY branch_city
   HAVING AVG(amount) > 1500;
   ```

   Without HAVING Clause:

   ```sql
   SELECT DISTINCT branch_city, Avg_amount
   FROM (
     SELECT DISTINCT branch_city, AVG(amount) AS Avg_amount
     FROM Branch B, Loan L
     WHERE B.branch_name = L.branch_name
     GROUP BY branch_city
   ) R
   WHERE Avg_amount > 1500;
   ```

   Question: For each branch city, find the average amount of loans where the average amount is greater than 1500.

5. **Find the customer name, customer street, customer city of the account which has the highest balance among all the accounts. (With and without using 'ALL' keyword)**

   With ALL Keyword:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
   FROM Customer C, Account A
   WHERE C.customer_name = (
     SELECT customer_name
     FROM Account
     WHERE balance >= ALL (SELECT balance FROM Account)
   );
   ```

   Without ALL Keyword:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
   FROM Customer C, Account A
   WHERE C.customer_name = (
     SELECT customer_name
     FROM Account
     WHERE balance = (SELECT MAX(balance) FROM Account)
   );
   ```

   Question: Find the customer information for the account with the highest balance.

6. **Find the customer name, customer street, customer city of the loan which has the lowest amount among all the loans. (With and without using 'ALL' keyword)**

   With ALL Keyword:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
   FROM Customer C, Loan L, Borrower Br
   WHERE C.customer_name = (
     SELECT customer_name
     FROM Loan
     WHERE amount <= ALL (SELECT amount FROM Loan)
   );
   ```

   Without ALL Keyword:

   ```sql
   SELECT DISTINCT C.customer_name, C.customer_street, C.customer_city
   FROM Customer C, Loan L, Borrower Br
   WHERE C.customer_name = (
     SELECT customer_name
     FROM Loan
     WHERE amount = (SELECT MIN(amount) FROM Loan)
   );
   ```

   Question: Find the customer information for the loan with the lowest amount.

7. **Find the distinct branches (name and city) that have opened both accounts and loans. (Using 'IN' and 'EXISTS' keyword)**

   Using IN Keyword:

   ```sql
   SELECT DISTINCT B.branch_name, B.branch_city
   FROM Branch B
   WHERE B.branch_name IN (
     SELECT DISTINCT A.branch_name
     FROM Account A
     WHERE A.branch_name IN (
       SELECT DISTINCT L.branch_name
       FROM Loan L
     )
   );
   ```

   Using EXISTS Keyword:

   ```sql
   SELECT DISTINCT B.branch_name, B.branch_city
   FROM Branch B
   WHERE EXISTS (
     SELECT * FROM Account A
     WHERE B.branch_name = A.branch_name
     AND EXISTS (
       SELECT * FROM Loan L
       WHERE A.branch_name = L.branch_name
   ```
