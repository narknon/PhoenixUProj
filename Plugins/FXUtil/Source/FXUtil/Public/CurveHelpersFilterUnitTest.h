#pragma once
#include "CoreMinimal.h"
#include "CurveHelpersUnitTest.h"
#include "CurveHelpersFilterUnitTest.generated.h"

UCLASS(Blueprintable)
class FXUTIL_API UCurveHelpersFilterUnitTest : public UCurveHelpersUnitTest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeConstant;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SolveTolerance;
    
    UCurveHelpersFilterUnitTest();
};

