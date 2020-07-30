float4 main(float3 position : Position) : SV_Position
{
	return float4(position.x, position.y, position.z, 1.f);
}