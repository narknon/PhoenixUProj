#pragma once
#include "CoreMinimal.h"
#include "ELumosContactShadows.h"
#include "LumosScalabilityModifyWithRule.h"
#include "LumosScalabilityModifyContactShadows.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosScalabilityModifyContactShadows : public ULumosScalabilityModifyWithRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELumosContactShadows ContactShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContactShadowLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyIfContactShadowsEnabled;
    
    ULumosScalabilityModifyContactShadows();
};

