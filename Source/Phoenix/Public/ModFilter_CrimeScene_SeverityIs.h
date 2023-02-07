#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.h"
#include "ModFilter_CrimeScene_Base.h"
#include "ModFilter_CrimeScene_SeverityIs.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_CrimeScene_SeverityIs : public UModFilter_CrimeScene_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EValueComparison Comparision;
    
public:
    UModFilter_CrimeScene_SeverityIs();
};

