#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "NiagaraDataInterfaceHoudini.generated.h"

class UHoudiniPointCache;

UCLASS(Blueprintable, EditInlineNew)
class HOUDININIAGARA_API UNiagaraDataInterfaceHoudini : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UHoudiniPointCache* HoudiniPointCacheAsset;
    
    UNiagaraDataInterfaceHoudini();
};

