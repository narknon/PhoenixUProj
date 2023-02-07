#pragma once
#include "CoreMinimal.h"
#include "EEasingFunction.generated.h"

UENUM(BlueprintType)
enum class EEasingFunction : uint8 {
    EF_None,
    EF_Back_In,
    EF_Back_Out,
    EF_Back_InOut,
    EF_Bounce_In,
    EF_Bounce_Out,
    EF_Bounce_InOut,
    EF_Circ_In,
    EF_Circ_Out,
    EF_Circ_InOut,
    EF_Cubic_In,
    EF_Cubic_Out,
    EF_Cubic_InOut,
    EF_Elastic_In,
    EF_Elastic_Out,
    EF_Elastic_InOut,
    EF_Expo_In,
    EF_Expo_Out,
    EF_Expo_InOut,
    EF_Linear_In,
    EF_Linear_Out,
    EF_Linear_InOut,
    EF_Quad_In,
    EF_Quad_Out,
    EF_Quad_InOut,
    EF_Quart_In,
    EF_Quart_Out,
    EF_Quart_InOut,
    EF_Quint_In,
    EF_Quint_Out,
    EF_Quint_InOut,
    EF_MAX UMETA(Hidden),
};

