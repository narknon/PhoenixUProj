#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsValidClass.generated.h"

class AActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsValidClass : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> ValidClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeParents;
    
public:
    UFXFilter_IsValidClass();
};

