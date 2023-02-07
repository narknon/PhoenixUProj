#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "FXAdjustments_UseBone.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_UseBone : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BoneNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailIfNotFound;
    
public:
    UFXAdjustments_UseBone();
};

