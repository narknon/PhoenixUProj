#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_Season.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_Season : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSummer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFall;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWinter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpring;
    
public:
    UFXFilter_Season();
};

