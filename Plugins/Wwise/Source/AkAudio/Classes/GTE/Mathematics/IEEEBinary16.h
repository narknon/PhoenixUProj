// David Eberly, Geometric Tools, Redmond WA 98052
// Copyright (c) 1998-2020
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt
// https://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
// Version: 4.0.2020.01.08

#pragma once

#include <Mathematics/BitHacks.h>
#include <Mathematics/Math.h>
#include <Mathematics/IEEEBinary.h>

namespace gte
{
    class IEEEBinary16 : public IEEEBinary<int16_t, uint16_t, 16, 11>
    {
    public:
        // Construction and destruction.  The base class destructor is hidden,
        // but this is safe because there are no side effects of the
        // destruction.
        ~IEEEBinary16() = default;

        IEEEBinary16()
            :
            IEEEBinary<int16_t, uint16_t, 16, 11>()
        {
            // uninitialized
        }

        IEEEBinary16(IEEEBinary16 const& object)
            :
            IEEEBinary<int16_t, uint16_t, 16, 11>(object)
        {
        }

        IEEEBinary16(float inNumber)
            :
            IEEEBinary<int16_t, uint16_t, 16, 11>()
        {
            union { float n; uint32_t e; } temp = { inNumber };
            encoding = Convert32To16(temp.e);
        }

        IEEEBinary16(double inNumber)
            :
            IEEEBinary<int16_t, uint16_t, 16, 11>()
        {
            union { float n; uint32_t e; } temp;
            temp.n = (float)inNumber;
            encoding = Convert32To16(temp.e);
        }

        IEEEBinary16(uint16_t inEncoding)
            :
            IEEEBinary<int16_t, uint16_t, 16, 11>(inEncoding)
        {
        }

        // Implicit conversions.
        operator float() const
        {
            union { uint32_t e; float n; } temp = { Convert16To32(encoding) };
            return temp.n;
        }

        operator double() const
        {
            union { uint32_t e; float n; } temp = { Convert16To32(encoding) };
            return (double)temp.n;
        }

        // Assignment.
        IEEEBinary16& operator=(IEEEBinary16 const& object)
        {
            IEEEBinary<int16_t, uint16_t, 16, 11>::operator=(object);
            return *this;
        }

        // Comparison.
        bool operator==(IEEEBinary16 const& object) const
        {
            return (float)*this == (float)object;
        }

        bool operator!=(IEEEBinary16 const& object) const
        {
            return (float)*this != (float)object;
        }

        bool operator< (IEEEBinary16 const& object) const
        {
            return (float)*this < (float)object;
        }

        bool operator<=(IEEEBinary16 const& object) const
        {
            return (float)*this <= (float)object;
        }

        bool operator> (IEEEBinary16 const& object) const
        {
            return (float)* this > (float)object;
        }

        bool operator>=(IEEEBinary16 const& object) const
        {
            return (float)* this >= (float)object;
        }

    private:
        // Support for conversions between encodings.
        enum
        {
            F32_NUM_ENCODING_BITS = 32,
            F32_NUM_TRAILING_BITS = 23,
            F32_EXPONENT_BIAS = 127,
            F32_MAX_BIASED_EXPONENT = 255,
            F32_SIGN_MASK = 0x80000000,
            F32_NOT_SIGN_MASK = 0x7FFFFFFF,
            F32_BIASED_EXPONENT_MASK = 0x7F800000,
            F32_TRAILING_MASK = 0x007FFFFF,
            F16_AVR_MIN_SUBNORMAL_ZERO = 0x33000000,
            F16_MIN_SUBNORMAL = 0x33800000,
            F16_MIN_NORMAL = 0x38800000,
            F16_MAX_NORMAL = 0x477FE000,
            F16_AVR_MAX_NORMAL_INFINITY = 0x477FF000,
            DIFF_NUM_ENCODING_BITS = 16,
            DIFF_NUM_TRAILING_BITS = 13,
            DIFF_PAYLOAD_SHIFT = 13,
            INT_PART_MASK = 0x007FE000,
            FRC_PART_MASK = 0x00001FFF,
            FRC_HALF = 0x00001000
        };

        static uint16_t Convert32To16(uint32_t inEncoding)
        {
            // Extract the channels for the binary32 number.
            uint32_t sign32 = (inEncoding & F32_SIGN_MASK);
            uint32_t biased32 =
                ((inEncoding & F32_BIASED_EXPONENT_MASK) >> F32_NUM_TRAILING_BITS);
            uint32_t trailing32 = (inEncoding & F32_TRAILING_MASK);
            uint32_t nonneg32 = (inEncoding & F32_NOT_SIGN_MASK);

            // Generate the channels for the IEEEBinary16 number.
            uint16_t sign16 = static_cast<uint16_t>(sign32 >> DIFF_NUM_ENCODING_BITS);
            uint16_t biased16, trailing16;
            uint32_t frcpart;

            if (biased32 == 0)
            {
                // nonneg32 is 32-zero or 32-subnormal, nearest is 16-zero.
                return sign16;
            }

            if (biased32 < F32_MAX_BIASED_EXPONENT)
            {
                // nonneg32 is 32-normal.
                if (nonneg32 <= F16_AVR_MIN_SUBNORMAL_ZERO)
                {
                    // nonneg32 <= 2^{-25}, nearest is 16-zero.
                    return sign16;
                }

                if (nonneg32 <= F16_MIN_SUBNORMAL)
                {
                    // 2^{-25} < nonneg32 <= 2^{-24}, nearest is
                    // 16-min-subnormal.
                    return sign16 | IEEEBinary16::MIN_SUBNORMAL;
                }

                if (nonneg32 < F16_MIN_NORMAL)
                {
                    // 2^{-24} < nonneg32 < 2^{-14}, round to nearest
                    // 16-subnormal with ties to even.  Note that biased16 is
                    // zero.
                    trailing16 = static_cast<uint16_t>(((trailing32 & INT_PART_MASK) >> DIFF_NUM_TRAILING_BITS));
                    frcpart = (trailing32 & FRC_PART_MASK);
                    if (frcpart > FRC_HALF || (frcpart == FRC_HALF && (trailing16 & 1)))
                    {
                        // If there is a carry into the exponent, the nearest
                        // is actually 16-min-normal 1.0*2^{-14}, so the
                        // high-order bit of trailing16 makes biased16 equal
                        // to 1 and the result is correct.
                        ++trailing16;
                    }
                    return sign16 | trailing16;
                }

                if (nonneg32 <= F16_MAX_NORMAL)
                {
                    // 2^{-14} <= nonneg32 <= 1.1111111111*2^{15}, round to
                    // nearest 16-normal with ties to even.
                    biased16 = static_cast<uint16_t>((biased32 - F32_EXPONENT_BIAS +
                        IEEEBinary16::EXPONENT_BIAS)
                        << IEEEBinary16::NUM_TRAILING_BITS);
                    trailing16 = static_cast<uint16_t>(((trailing32 & INT_PART_MASK) >> DIFF_NUM_TRAILING_BITS));
                    frcpart = (trailing32 & FRC_PART_MASK);
                    if (frcpart > FRC_HALF || (frcpart == FRC_HALF && (trailing16 & 1)))
                    {
                        // If there is a carry into the exponent, the addition
                        // of trailing16 to biased16 (rather than or-ing)
                        // produces the correct result.
                        ++trailing16;
                    }
                    return sign16 | (biased16 + trailing16);
                }

                if (nonneg32 < F16_AVR_MAX_NORMAL_INFINITY)
                {
                    // 1.1111111111*2^{15} < nonneg32 < (MAX_NORMAL+INFINITY)/2,
                    // so the number is closest to 16-max-normal.
                    return sign16 | IEEEBinary16::MAX_NORMAL;
                }

                // nonneg32 >= (MAX_NORMAL+INFINITY)/2, so convert to
                // 16-infinite.
                return sign16 | IEEEBinary16::POS_INFINITY;
            }

            if (trailing32 == 0)
            {
                // The number is 32-infinite.  Convert to 16-infinite.
                return sign16 | IEEEBinary16::POS_INFINITY;
            }

            // The number is 32-NaN.  Convert to 16-NaN with 16-payload the
            // high-order 9 bits of the 32-payload.  The code also grabs the
            // 32-quietNaN mask bit.
            uint16_t maskPayload = static_cast<uint16_t>((trailing32 & 0x007FE000u) >> 13);
            return sign16 | IEEEBinary16::EXPONENT_MASK | maskPayload;
        }

        static uint32_t Convert16To32(uint16_t inEncoding)
        {
            // Extract the channels for the IEEEBinary16 number.
            uint16_t sign16 = (inEncoding & IEEEBinary16::SIGN_MASK);
            uint16_t biased16 = ((inEncoding & IEEEBinary16::EXPONENT_MASK) >> IEEEBinary16::NUM_TRAILING_BITS);
            uint16_t trailing16 = (inEncoding & IEEEBinary16::TRAILING_MASK);

            // Generate the channels for the binary32 number.
            uint32_t sign32 = static_cast<uint32_t>(sign16 << DIFF_NUM_ENCODING_BITS);
            uint32_t biased32, trailing32;

            if (biased16 == 0)
            {
                if (trailing16 == 0)
                {
                    // The number is 16-zero.  Convert to 32-zero.
                    return sign32;
                }
                else
                {
                    // The number is 16-subnormal.  Convert to 32-normal.
                    trailing32 = static_cast<uint32_t>(trailing16);
                    int32_t leading = BitHacks::GetLeadingBit(trailing32);
                    int32_t shift = 23 - leading;
                    biased32 = static_cast<uint32_t>(F32_EXPONENT_BIAS - 1 - shift);
                    trailing32 = (trailing32 << shift) & F32_TRAILING_MASK;
                    return sign32 | (biased32 << F32_NUM_TRAILING_BITS) | trailing32;
                }
            }

            if (biased16 < IEEEBinary16::MAX_BIASED_EXPONENT)
            {
                // The number is 16-normal.  Convert to 32-normal.
                biased32 = static_cast<uint32_t>(biased16 - IEEEBinary16::EXPONENT_BIAS + F32_EXPONENT_BIAS);
                trailing32 = (static_cast<uint32_t>(trailing16) << DIFF_NUM_TRAILING_BITS);
                return sign32 | (biased32 << F32_NUM_TRAILING_BITS) | trailing32;
            }

            if (trailing16 == 0)
            {
                // The number is 16-infinite.  Convert to 32-infinite.
                return sign32 | F32_BIASED_EXPONENT_MASK;
            }

            // The number is 16-NaN.  Convert to 32-NaN with 16-payload
            // embedded in the high-order 9 bits of the 32-payload.  The
            // code also copies the 16-quietNaN mask bit.
            uint32_t maskPayload = ((trailing16 & IEEEBinary16::TRAILING_MASK) << DIFF_PAYLOAD_SHIFT);
            return sign32 | F32_BIASED_EXPONENT_MASK | maskPayload;
        }
    };

    // Arithmetic operations (high-precision).
    inline IEEEBinary16 operator-(IEEEBinary16 x)
    {
        uint16_t result = static_cast<uint16_t>(x) ^ IEEEBinary16::SIGN_MASK;
        return result;
    }

    inline float operator+(IEEEBinary16 x, IEEEBinary16 y)
    {
        return static_cast<float>(x) + static_cast<float>(y);
    }

    inline float operator-(IEEEBinary16 x, IEEEBinary16 y)
    {
        return static_cast<float>(x) - static_cast<float>(y);
    }

    inline float operator*(IEEEBinary16 x, IEEEBinary16 y)
    {
        return static_cast<float>(x)* static_cast<float>(y);
    }

    inline float operator/(IEEEBinary16 x, IEEEBinary16 y)
    {
        return static_cast<float>(x) / static_cast<float>(y);
    }

    inline float operator+(IEEEBinary16 x, float y)
    {
        return static_cast<float>(x) + y;
    }

    inline float operator-(IEEEBinary16 x, float y)
    {
        return static_cast<float>(x) - y;
    }

    inline float operator*(IEEEBinary16 x, float y)
    {
        return static_cast<float>(x)* y;
    }

    inline float operator/(IEEEBinary16 x, float y)
    {
        return static_cast<float>(x) / y;
    }

    inline float operator+(float x, IEEEBinary16 y)
    {
        return x + static_cast<float>(y);
    }

    inline float operator-(float x, IEEEBinary16 y)
    {
        return x - static_cast<float>(y);
    }

    inline float operator*(float x, IEEEBinary16 y)
    {
        return x * static_cast<float>(y);
    }

    inline float operator/(float x, IEEEBinary16 y)
    {
        return x / static_cast<float>(y);
    }

    // Arithmetic updates.
    inline IEEEBinary16& operator+=(IEEEBinary16& x, IEEEBinary16 y)
    {
        x = static_cast<float>(x) + static_cast<float>(y);
        return x;
    }

    inline IEEEBinary16& operator-=(IEEEBinary16& x, IEEEBinary16 y)
    {
        x = static_cast<float>(x) - static_cast<float>(y);
        return x;
    }

    inline IEEEBinary16& operator*=(IEEEBinary16& x, IEEEBinary16 y)
    {
        x = static_cast<float>(x) * static_cast<float>(y);
        return x;
    }

    inline IEEEBinary16& operator/=(IEEEBinary16& x, IEEEBinary16 y)
    {
        x = static_cast<float>(x) / static_cast<float>(y);
        return x;
    }

    inline IEEEBinary16& operator+=(IEEEBinary16& x, float y)
    {
        x = static_cast<float>(x) + y;
        return x;
    }

    inline IEEEBinary16& operator-=(IEEEBinary16& x, float y)
    {
        x = static_cast<float>(x) - y;
        return x;
    }

    inline IEEEBinary16& operator*=(IEEEBinary16& x, float y)
    {
        x = static_cast<float>(x) * y;
        return x;
    }

    inline IEEEBinary16& operator/=(IEEEBinary16& x, float y)
    {
        x = static_cast<float>(x) / y;
        return x;
    }
}

namespace std
{
    inline gte::IEEEBinary16 acos(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::acos((float)x);
    }

    inline gte::IEEEBinary16 acosh(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::acosh((float)x);
    }

    inline gte::IEEEBinary16 asin(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::asin((float)x);
    }

    inline gte::IEEEBinary16 asinh(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::asin((float)x);
    }

    inline gte::IEEEBinary16 atan(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::atan((float)x);
    }

    inline gte::IEEEBinary16 atanh(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::atanh((float)x);
    }

    inline gte::IEEEBinary16 atan2(gte::IEEEBinary16 y, gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::atan2((float)y, (float)x);
    }

    inline gte::IEEEBinary16 ceil(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::ceil((float)x);
    }

    inline gte::IEEEBinary16 cos(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::cos((float)x);
    }

    inline gte::IEEEBinary16 cosh(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::cosh((float)x);
    }

    inline gte::IEEEBinary16 exp(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::exp((float)x);
    }

    inline gte::IEEEBinary16 exp2(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::exp2((float)x);
    }

    inline gte::IEEEBinary16 fabs(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::fabs((float)x);
    }

    inline gte::IEEEBinary16 floor(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::floor((float)x);
    }

    inline gte::IEEEBinary16 fmod(gte::IEEEBinary16 x, gte::IEEEBinary16 y)
    {
        return (gte::IEEEBinary16)std::fmod((float)x, (float)y);
    }

    inline gte::IEEEBinary16 frexp(gte::IEEEBinary16 x, int* exponent)
    {
        return (gte::IEEEBinary16)std::frexp((float)x, exponent);
    }

    inline gte::IEEEBinary16 ldexp(gte::IEEEBinary16 x, int exponent)
    {
        return (gte::IEEEBinary16)std::ldexp((float)x, exponent);
    }

    inline gte::IEEEBinary16 log(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::log((float)x);
    }

    inline gte::IEEEBinary16 log2(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::log2((float)x);
    }

    inline gte::IEEEBinary16 log10(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::log10((float)x);
    }

    inline gte::IEEEBinary16 pow(gte::IEEEBinary16 x, gte::IEEEBinary16 y)
    {
        return (gte::IEEEBinary16)std::pow((float)x, (float)y);
    }

    inline gte::IEEEBinary16 sin(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::sin((float)x);
    }

    inline gte::IEEEBinary16 sinh(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::sinh((float)x);
    }

    inline gte::IEEEBinary16 sqrt(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::sqrt((float)x);
    }

    inline gte::IEEEBinary16 tan(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::tan((float)x);
    }

    inline gte::IEEEBinary16 tanh(gte::IEEEBinary16 x)
    {
        return (gte::IEEEBinary16)std::tanh((float)x);
    }
}

namespace gte
{
    inline IEEEBinary16 atandivpi(IEEEBinary16 x)
    {
        return (IEEEBinary16)atandivpi((float)x);
    }

    inline IEEEBinary16 atan2divpi(IEEEBinary16 y, IEEEBinary16 x)
    {
        return (IEEEBinary16)atan2divpi((float)y, (float)x);
    }

    inline IEEEBinary16 clamp(IEEEBinary16 x, IEEEBinary16 xmin, IEEEBinary16 xmax)
    {
        return (IEEEBinary16)clamp((float)x, (float)xmin, (float)xmax);
    }

    inline IEEEBinary16 cospi(IEEEBinary16 x)
    {
        return (IEEEBinary16)cospi((float)x);
    }

    inline IEEEBinary16 exp10(IEEEBinary16 x)
    {
        return (IEEEBinary16)exp10((float)x);
    }

    inline IEEEBinary16 invsqrt(IEEEBinary16 x)
    {
        return (IEEEBinary16)invsqrt((float)x);
    }

    inline int isign(IEEEBinary16 x)
    {
        return isign((float)x);
    }

    inline IEEEBinary16 saturate(IEEEBinary16 x)
    {
        return (IEEEBinary16)saturate((float)x);
    }

    inline IEEEBinary16 sign(IEEEBinary16 x)
    {
        return (IEEEBinary16)sign((float)x);
    }

    inline IEEEBinary16 sinpi(IEEEBinary16 x)
    {
        return (IEEEBinary16)sinpi((float)x);
    }

    inline IEEEBinary16 sqr(IEEEBinary16 x)
    {
        return (IEEEBinary16)sqr((float)x);
    }
}
