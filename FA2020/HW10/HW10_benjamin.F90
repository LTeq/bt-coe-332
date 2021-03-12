! Technically if this was a real Module I would put it in a separate file, but that would not work for the grader from what I've been told.
Module coordinateSystem
  ! Creates the point type with members x, y.
  type point
     real :: x,y
  end type point

  ! Creates the rectangle type with members of points.
  type rectangle 
     Type(point) :: lowerLeft, upperRight
  end type rectangle

  ! Creates a function area that returns the area of a rectangle.
contains
  real(4) function areaRect(a)
    implicit none
    Type(rectangle), intent(in) :: a
    ! Subtracts the coordinates of the points of the rectangle.
    ! Abs just in case the coordinates are inputted backwards.
    areaRect = abs((a%upperRight%x - a%lowerLeft%x) * (a%upperRight%y - a%lowerLeft%y))
  end function areaRect
end Module coordinateSystem

Program areaCalc
  ! Allows usage of the module coordinateSystem.
  use coordinateSystem
  implicit none

  ! Declaration.
  Type(point) :: p1, p2
  Type(rectangle) :: r
  real :: area

  real :: x1, y1, x2, y2
  ! Accepts user input.
  ! Accepts input of order of x then y coordinate of lowerLeft and then upperRight respectively.
  read(*,*) x1, y1, x2, y2
  p1 = point(x1, y1)
  p2 = point(x2, y2)

  ! Sets the rectangle r to have lowerLeft point p1, and upperRight point p2.
  r = rectangle(p1, p2)
  area = areaRect(r)

  ! Prints the area of r.
  print *, area
  

end Program areaCalc

