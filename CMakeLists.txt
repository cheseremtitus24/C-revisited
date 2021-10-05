cmake_minimum_required(VERSION 3.20)
project(03coupon_SebastianGabrai)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(03coupon_SebastianGabrai
        Coupon.cpp
        Coupon.h
        Date.cpp
        Date.h
        DeductionCoupon.cpp
        DeductionCoupon.h
        main.cpp
        PercentageCoupon.cpp
        PercentageCoupon.h
        )

