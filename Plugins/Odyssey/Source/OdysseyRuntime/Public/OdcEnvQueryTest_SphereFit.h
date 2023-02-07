#pragma once
#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "OdcPathSpec.h"
#include "OdcEnvQueryTest_SphereFit.generated.h"

UCLASS(Blueprintable)
class ODYSSEYRUNTIME_API UOdcEnvQueryTest_SphereFit : public UEnvQueryTest {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomPathSpec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcPathSpec CustomPathSpec;
    
public:
    UOdcEnvQueryTest_SphereFit();
};

