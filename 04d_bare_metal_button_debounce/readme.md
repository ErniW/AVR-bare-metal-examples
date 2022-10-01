## Button debouncing
When button is released you can see that it suddenly switch the pin state again. Why? When releasing a button it generates a small noise in current which interrupt threads as another button press. 

- Using interrupt is not a good case for that.
- You can add a small delay after your function.
- You can add a simple counter which temporaily disables reading of that port. (You can add a flag for that).

*Upload the code to see how it differs from previous example. It's not perfect but works.*