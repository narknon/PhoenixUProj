#pragma once
#include "CoreMinimal.h"
#include "CurveHelpersUnitTest.h"
#include "CurveHelpersSimpleUnitTest.generated.h"

UCLASS(Blueprintable)
class FXUTIL_API UCurveHelpersSimpleUnitTest : public UCurveHelpersUnitTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Start;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Duration;
    
    UCurveHelpersSimpleUnitTest();
};

