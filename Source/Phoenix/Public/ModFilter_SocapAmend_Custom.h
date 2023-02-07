#pragma once
#include "CoreMinimal.h"
#include "EValueComparison.h"
#include "MODFilter_SocapAmend_Base.h"
#include "SocapAmendInfo.h"
#include "SocialReasoningComparison.h"
#include "SocialSemanticsComparison.h"
#include "ModFilter_SocapAmend_Custom.generated.h"

class UObject;

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_SocapAmend_Custom : public UMODFilter_SocapAmend_Base {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseValueFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EValueComparison ComparisonOperator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComparisonValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSocialReasoningFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSocialReasoningComparison SocialReasoningFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSocialSemanticsFilter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSocialSemanticsComparison SocialSemanticsFilter;
    
public:
    UModFilter_SocapAmend_Custom();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool BlueprintPassesSocapFilter(const UObject* InTargetObject, const FSocapAmendInfo& SocapInfo) const;
    
};

