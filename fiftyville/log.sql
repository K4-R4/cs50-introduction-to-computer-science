-- Keep a log of any SQL queries you execute as you solve the mystery.
.tables
.schema crime_scene_reports
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present at the time –
--each of their interview transcripts mentions the bakery.
.schema interviews
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";
--Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
--If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

--I don't know the thief's name, but it was someone I recognized.
--Earlier this morning, before I arrived at Emma's bakery,
--I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.
.schema bakery_security_logs
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit";

.schema atm_transactions
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
.schema bank_accounts
SELECT person_id FROM bank_accounts
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";

.schema phone_calls
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

.schema people
SELECT people.name, people.passport_number FROM people
    WHERE id IN (SELECT person_id FROM bank_accounts
        JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
    AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
    AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit");

.schema flights
.schema passengers
SELECT flight_id FROM passengers
    WHERE passport_number IN (
        SELECT people.passport_number FROM people
            WHERE id IN (SELECT person_id FROM bank_accounts
                JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
            AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
            AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit")
            );

SELECT * FROM flights
    WHERE id IN (SELECT flight_id FROM passengers
        WHERE passport_number IN (
            SELECT people.passport_number FROM people
                WHERE id IN (SELECT person_id FROM bank_accounts
                    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
                AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
                AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit")
                ))
    AND year = 2021 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1;
--id 36
--origin airport 8, destination airport 4

.schema airports
SELECT * FROM airports WHERE id = 8 OR id = 4;
--Fiftyville to New York City

SELECT passport_number FROM passengers
    WHERE passport_number IN (
        SELECT people.passport_number FROM people
            WHERE id IN (SELECT person_id FROM bank_accounts
                JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
            AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
            AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit")
            )
    AND flight_id = 36;

SELECT * FROM people
    WHERE passport_number IN (SELECT passport_number FROM passengers
        WHERE passport_number IN (
            SELECT people.passport_number FROM people
                WHERE id IN (SELECT person_id FROM bank_accounts
                    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                    WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
                AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
                AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit")
                )
        AND flight_id = 36);
--Bruce

SELECT * FROM phone_calls
    WHERE caller IN (SELECT phone_number FROM people
        WHERE passport_number IN (SELECT passport_number FROM passengers
            WHERE passport_number IN (
                SELECT people.passport_number FROM people
                    WHERE id IN (SELECT person_id FROM bank_accounts
                        JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                        WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
                    AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60)
                    AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute < 25 AND activity = "exit")
                    )
            AND flight_id = 36)
    )
    AND year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- Bruce (367) 555-5533 | (375) 555-8161

SELECT name FROM people WHERE phone_number = "(375) 555-8161";
--Robin