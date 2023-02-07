#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "EMultiFXCompare.h"
#include "EMultiFXPropertyOwner.h"
#include "EMultiFXVectorExtension.h"
#include "FXFilter_ValuePropertyCompare.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_ValuePropertyCompare : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXPropertyOwner PropertyOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXCompare Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXVectorExtension VectorUsage;
    
public:
    UFXFilter_ValuePropertyCompare();
};

