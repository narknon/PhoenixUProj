#pragma once
#include "CoreMinimal.h"
#include "CurveHelpersSimpleUnitTest.h"
#include "EasingFunction.h"
#include "CurveHelpersEaseUnitTest.generated.h"

UCLASS(Blueprintable)
class FXUTIL_API UCurveHelpersEaseUnitTest : public UCurveHelpersSimpleUnitTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEasingFunction Easing;
    
    UCurveHelpersEaseUnitTest();
};

