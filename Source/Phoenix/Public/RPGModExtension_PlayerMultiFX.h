#pragma once
#include "CoreMinimal.h"
#include "ModExtension.h"
#include "MultiFXPlus.h"
#include "MultiFXPlusHandles.h"
#include "RPGModExtension_PlayerMultiFX.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URPGModExtension_PlayerMultiFX : public UModExtension {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXPlus OnAddEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXPlus OnAppliedEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyOnFirstApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyAllowOneApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEndAppliedOnRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXPlus OnRemovedEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMultiFXPlusHandles OnAddHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMultiFXPlusHandles OnAppliedHandle;
    
    URPGModExtension_PlayerMultiFX();
};

