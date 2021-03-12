program testIfPrime

  implicit none
  
  ! userInput stores number of variables for printing, mynumber is incrementor for checking numbers.
  integer :: userInput, mynumber, i, j, count
  logical :: isprime = .TRUE.
  
  print *, 'Enter an integer: '
  read *, userInput
  count = 0
  mynumber = 2

  do while (count < userInput)
     ! Checks odd numbers and excludes 1 as prime.
     ! This would be better as a function, but I already had this code written before learning about them.
     if (mynumber == 2 .OR. mynumber == 3) then
        isprime = .TRUE.
     else if (mod(mynumber, 2) == 0 .OR. mynumber == 1) then
        isprime = .FALSE.
     else
        do i = 3, mynumber/2, 2
           if (mod(mynumber, i) == 0) then
              isprime = .FALSE.
           end if
        end do
     end if

     ! If mynumber is prime, then that means we want to print it and increase counter by 1.
     if(isprime) then
        count = count + 1
        print *, mynumber
     end if

     ! Resets values of isprime and sets value of mynumber
     isprime = .TRUE.
     mynumber = mynumber + 1
  end do

end program testIfPrime
