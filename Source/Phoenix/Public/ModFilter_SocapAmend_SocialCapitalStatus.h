#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.h"
#include "MODFilter_SocapAmend_Base.h"
#include "SocialCapitalStatusIDs.h"
#include "ModFilter_SocapAmend_SocialCapitalStatus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_SocapAmend_SocialCapitalStatus : public UMODFilter_SocapAmend_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EValueComparison ComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<SocialCapitalStatusIDs> SocialCapitalStatus;
    
public:
    UModFilter_SocapAmend_SocialCapitalStatus();
};

