#pragma once
#include "CoreMinimal.h"
#include "VectorField/VectorField.h"

#include "VectorFieldFluidSim.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UVectorFieldFluidSim : public UVectorField {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SizeX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SizeY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SizeZ;
    
    UVectorFieldFluidSim();

    //~ Begin UVectorField Interface
    virtual void InitInstance(class FVectorFieldInstance* Instance, bool bPreviewInstance) override;
    //~ End UVectorField Interface
};

