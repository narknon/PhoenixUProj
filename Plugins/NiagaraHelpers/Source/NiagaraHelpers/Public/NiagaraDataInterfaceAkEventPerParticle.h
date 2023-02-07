#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "NiagaraDataInterfaceAkEventInfo.h"
#include "NiagaraDataInterfaceAkEventPerParticle.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class NIAGARAHELPERS_API UNiagaraDataInterfaceAkEventPerParticle : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FNiagaraDataInterfaceAkEventInfo> Events;
    
    UNiagaraDataInterfaceAkEventPerParticle();
};

